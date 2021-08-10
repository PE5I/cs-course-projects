# the scanner.py file should be included in the same working directory as this script
from scanner import Scanner



def parse_username(username):
    '''
    parse_username takes a string as argument and returns a string of a Twitter username without '@' 
    '''
    parsed = username.replace("@", "") # If it was this simple, I'm not sure if it warrants a function :/
    return parsed
    

def read_records(infile):
    '''
    Takes a filename as argument, creates a Scanner object and a record for each line in the file.
    read_records returns a list containing the records
    '''
    # The expected infile format is
    # String, String, Integer, Integer, Integer, Integer:Integer:Integer
    s = Scanner(infile)
    
    #'''
    records = []
    with open(infile) as readfile:
        # Loop through file line by line until "EOF"
        for i in readfile:
            #parsed = create_record(s)
            records.append(s)
    #'''
         
    return records

def create_record(scanner_record):
    '''
    Takes in a Scanner object, parses it, then return back a string of the 
    parsed Scanner object.
    '''
    records = []
    
    j = 0
    for i in scanner_record:
        username = parse_username(scanner_record[j].readtoken())
        tweet = scanner_record[j].readstring()
        year = scanner_record[j].readint()
        month = scanner_record[j].readint()
        day = scanner_record[j].readint()
        
        hour = scanner_record[j].readint()
        _ = scanner_record[j].readrawchar() # nice way of not reading ':' in the time format
        minute = scanner_record[j].readint()
        _ = scanner_record[j].readrawchar()
        second = scanner_record[j].readint()
        j += 1
    #num_records += 1
    
        user_tweet = username + " " + tweet + " " + " " \
                    + str(year) + " " + str(month) + " " + str(day) + " " \
                    + str(hour) + ":" + str(minute) + ":" + str(second)
        records.append(user_tweet)
    
    return records

def get_day(string):
    '''
    get_day() takes a record and parses the string to get the year of the post
    get_day() returns an integer representing the month in the Gregorian/Julian calendar
    '''
    # The idea to split string was inspired by user 6502 on https://stackoverflow.com/a/26825744
    # The other way I did it was messier (for i in range(x,y): ''.join(string[x-y]))
    string = string.split()
    day = string[-2] # the day is always at the indice -2
    day = int(day)

    return day

def get_month(string):
    '''
    get_month() takes a record and parses the string to get the year of the post
    get_month() returns an integer representing the month in the Gregorian/Julian calendar
    '''
    string = string.split()
    month = string[-3] # the month is always at the indice -3
    month = int(month)
    
    return month

def get_year(string):
    '''
    get_year() takes a tweet record and parses the string to get the year of the post
    get_year() returns an integer representing the year in the Gregorian/Julian calendar
    '''
    string = string.split()
    year = string[-4] # the year is always the indice -4
    # converts string to an integral type... potential problem here if year contains an ASCII character that isn't integral in nature
    year = int(year)
    
    return year

def get_hour(string):
    '''
    Takes a record as string. Splits string into a list. Indice the list to get the time
    field. Then we indice the time field again to find the hour
    '''
    # split string
    string = string.split()
    # get time field
    time = string[-1]
    # split time field using the ':' as delimiter
    time = time.split(':')
    # time format is hh:mm:ss
    hour = time[0]
    
    return hour

def get_minutes(string):
    # split string
    string = string.split()
    # get time field
    time = string[-1]
    # split time field using the ':' as delimiter
    time = time.split(':')
    # time format is hh:mm:ss
    minutes = time[1]

    return minutes

def get_seconds(string):
    # split string
    string = string.split()
    # get time field
    time = string[-1]
    # split time field using the ':' as delimiter
    time = time.split(':')
    # time format is hh:mm:ss
    seconds = time[2]
    
    return seconds

def is_more_recent(r_1, r_2):
    '''
    is_more_recent() compares two Scanner objects based on date and returns 
    True if first record is more recent than the second, False otherwise
    '''
    
    # Get date information for record 1 (r_1)
    year_1 = get_year(r_1)
    month_1 = get_month(r_1)
    day_1 = get_day(r_1)
    hour_1 = get_hour(r_1)
    minutes_1 = get_minutes(r_1)
    seconds_1 = get_seconds(r_1)
    
    # Get date information for record 2 (r_2)
    year_2 = get_year(r_2)
    month_2 = get_month(r_2)
    day_2 = get_day(r_2)
    hour_2 = get_hour(r_2)
    minutes_2 = get_minutes(r_2)
    seconds_2 = get_seconds(r_2)
    
    # We assume initially that r_1 is not recent
    is_recent = False
    
    # We test to see if there's a date field (yr,month,day,hour,minutes,seconds) that would prove otherwise
    if(year_1 > year_2):
        is_recent = True
    elif(month_1 > month_2 and (year_1 == year_2)):
        is_recent = True
    elif(day_1 > day_2 and (month_1 == month_2) and (year_1 == year_2)):
        is_recent = True  
    # In the case year_1 == year_2, we check months. If month_1 == month_2, we check days. If day_1 == day_2, then we know they were posted the same
    # day. So we return False for "otherwise."
    
    # I hope to also check the timestamp, but there's some concerns with the logic... so will implement later
    '''elif(hour_1 > hour_2 and day_1 > day_2 and (month_1 == month_2) and (year_1 == year_2)): # if dates are the same, then we check the timestamp
        is_recent = True
    elif(minutes_1 > minutes_2 and hour_1 > hour_2 and day_1 > day_2 and (month_1 == month_2) and (year_1 == year_2)):
        is_recent = True
    elif(seconds_1 > seconds_2 and minutes_1 > minutes_2 and hour_1 > hour_2 and day_1 > day_2 and (month_1 == month_2) and (year_1 == year_2)):
        is_recent = True
    '''

    return is_recent

def merge_and_sort_tweets(record_1, record_2):
    
    # Combine the list into one
    combined_records = record_1 + record_2
    
    # Reversed Bubble Sort
    for i in range(0, len(combined_records)):
        for j in range(0, len(combined_records)-1):
            if( not(is_more_recent(combined_records[j], combined_records[j+1]) )):
                temp = combined_records[j+1]
                combined_records[j+1] = combined_records[j]
                combined_records[j] = temp
    
    # By time we reach here, the list should be sorted
    return combined_records

def write_records(records):
    filename = "sorted_tweets.txt"
    file = open(filename, "w")

    for i in records:
        file.write(i)
        file.write("\n")
        
    file.close()
    
    

# Define "hashtag" to be the pound sign
def most_used_hashtag(record):
    '''
    most_used_hashtag() takes a list of record as an argument and returns a string of the most used pound sign name
    '''
    
    hashtag = dict()
    key = '#'
    for i in range(0, len(record)):
        record[i]
    pass

def tweet_overlimit(record):
    num_short_tweet = 0
    num_long_tweet = 0
    
    for i in record:
        fields = i.split('"')
        tweet = fields[1]
        if(len(tweet) > 140):
            num_long_tweet += 1
        elif(len(tweet) < 50):
            num_short_tweet += 1
    
    return num_long_tweet, num_short_tweet

def main():
    tweet_file = ["tweet1.txt", "tweet2.txt"]
    
    print("Python 3.6 -- Twitter Harvester\n")
    
    print("Reading files...")
    data_1 = read_records(tweet_file[0])
    data_2 = read_records(tweet_file[1])
    
    if (len(data_1) > len(data_2)):
        print("%s contained the most tweet with %d" %(tweet_file[0], len(data_1)))
    else:
        print("%s contained the most tweet with %d" %(tweet_file[1], len(data_2)))
    
    print("Formatting data...")
    records_1 = create_record(data_1)
    records_2 = create_record(data_2)
    
    print("Now merging and sorting files...")
    sorted_records = merge_and_sort_tweets(records_1, records_2)
    
    #most_used_hashtag(sorted_records)
    
    print("Writing file...")
    write_records(sorted_records)
    print("Write done!")
    
    print("Displaying 5 earliest tweeters and tweets:")
    i = -1
    while(i >= -6):
        # My solution doesn't look very elegant. I'm sure there's a much more organized way of doing this
        fields = sorted_records[i].split("\"") # Split the sorted records by "
        # Indice the first string (tweeter) and the second string (tweet)
        print("(%d) %s\"%s\"%s" %(i*-1, fields[0], fields[1], fields[-1]))
        i -= 1
    
    print("\nBonus implementation:")
    long_tweet, short_tweet = tweet_overlimit(sorted_records)
    print("Tweet Statistics: %d tweet(s) over the character limit, and %d \"short\" tweet(s)." %(long_tweet, short_tweet))
    

# Start execution 
main()