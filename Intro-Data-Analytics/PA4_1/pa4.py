class Node:
    
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None
        
    #def __str__(self):
    #    return str(self.data)

    def get_data(self):
        return self.data
    
    def get_prev(self):
        return self.prev
    
    def get_next(self):
        return self.next

    def set_data(self, newdata):
        self.data = newdata

    def set_next(self, new_next):
        self.next = new_next
    
    def set_prev(self, new_prev):
        self.prev = new_prev


class HashTable(Node):
    '''
    
    '''
    def __init__(self, size=11):
        '''
        
        '''
        self.size = size
        self.slots = [None] * self.size


    def put(self, item):
        '''
        Place an item in the hash table.
        Return slot number if successful, -1 otherwise (no available slots, table is full)
        '''
        hashvalue = self.hashfunction(item)
        slot_placed = -1
        if self.slots[hashvalue] == None or self.slots[hashvalue] == item: # empty slot or slot contains item already
            self.slots[hashvalue] = item
            slot_placed = hashvalue
        else:
            nextslot = self.rehash(hashvalue)
            while self.slots[nextslot] != None and self.slots[nextslot] != item: 
                nextslot = self.rehash(nextslot)
                if nextslot == hashvalue: # we have done a full circle through the hash table
                    # no available slots
                    return slot_placed

            self.slots[nextslot] = item
            slot_placed = nextslot
        return slot_placed
        
    def get(self, item):
        '''
        returns slot position if item in hashtable, -1 otherwise
        '''
        startslot = self.hashfunction(item)
        
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == item:
                found = True
            else:
                position=self.rehash(position)
                if position == startslot:
                    stop = True
        if found:
            return position
        return -1
    
    def remove(self, item):
        '''
        Removes item.
        Returns slot position if item in hashtable, -1 otherwise
        '''
        startslot = self.hashfunction(item)
        
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == item:
                found = True
                self.slots[position] = None
            else:
                position=self.rehash(position)
                if position == startslot:
                    stop = True
        if found:
            return position
        return -1
###
    def hashfunction(self, item):
        '''
        Remainder method
        '''
        return item % self.size

    def rehash(self, hash_head):
        '''
        Plus 1 rehash for chaining probing
        '''
        return (hash_head + 1) % self.size


#h1 = HashTable()
#print(h1.put(11))
#print(h1.slots)

class Map(HashTable):
    '''

    '''
    def __init__(self, size=11):
        '''

        '''
        super().__init__(size)
        self.values = [None] * self.size # holds values

    def __str__(self):
        '''

        '''
        s = ""
        for slot, key in enumerate(self.slots):
            value = self.values[slot]
            s += str(key) + ":" + str(value) + ", "
        return s

    def __len__(self):
        '''
        Return the number of key-value pairs stored in the map.
        '''
        count = 0
        for item in self.slots:
            if item is not None:
                count += 1
        return count

    def __getitem__(self, key):
        '''

        '''
        return self.get(key)

    def __setitem__(self, key, data):
        '''

        '''
        self.put(key,data)

    def __delitem__(self, key):
        '''

        '''
        self.remove(key)

    def __contains__(self, key):
        '''

        '''
        return self.get(key) != -1


    def put(self, key, value):
        '''
        Add a new key-value pair to the map. If the key is already in the map then replace the old value with the new value.
        '''
        slot = super().put(key)
        if slot != -1:
            self.values[slot] = value
        return -1

    def get(self, key):
        '''

        '''
        slot = super().get(key)
        if slot != -1:
            return self.values[slot]
        return -1

    def remove(self, key):
        '''
        Removes key:value pair.
        Returns slot location if item in hashtable, -1 otherwise
        '''
        slot = super().remove(key)
        if slot != -1:
            self.values[slot] = None
        return slot

    def hashfunction(self, item):
        '''
        Remainder method
        '''
        key = 0
        for x in item:
            key += ord(x)
        return key % self.size

'''
m = Map()
m["cat"] = 0
m["dog"] = 0
m["dog"] = 0
print(m)



m["llama"] = len("llama")
m["rooster"] = len("rooster")
print(m)
# hash table is full, no room to put again
m["fish"] = len("fish")
print(m)
del m["lion"]
print(m)
print(len(m))
print("cow" in m)
print("fish" in m)
'''
###########################################################

class DictEntry:
    def __init__(self, word, prob):
        self.word = word # string
        self.prob = prob # float

    def __set_prob__(self, newprob):
        self.prob = newprob

    # getter for the word
    def get_word(self): # returns string
        return self.word

    # getter for the probablity
    def get_prob(self): # returns float
        return self.prob

    # does this word match a pattern?
    def match_pattern(self, pattern):
        if(self.prob > 0): # What a mysterious function
            return True
        else:
            return False

class WordPredictor:
    def __init__(self):
        self.word_to_count = {}
        self.total = 0
        self.prefix_to_entry = {}

    # train the unigram model on all the words in the given file
    def train(self, training_file):  # string
        try:
            newfile = open(training_file, "r")
            print("Now training on %s" %(training_file))
            for line in newfile:
                for word in line.split():
                    # Remove punctuation
                    word = word.replace(",", "")
                    word = word.replace(".", "")
                    word = word.replace("!", "")
                    word = word.replace("?", "")
                    word = word.replace(";", "")
                    word = word.replace(":", "")
                    word = word.replace("-", "")
                    word = word.replace("\"", "")
                    word = word.replace("\$", "")
                    word = word.lower()

                    self.train_word(word)
            print("Total words: %d" %(self.total))
        except IOError:
            print("Could not open training file: %s" %(training_file))
            return 0

    # train on just a single word
    def train_word(self, word):  # string
        #print("Training")

        if(word in self.word_to_count):
            self.word_to_count[word] += 1
        else:
            self.word_to_count[word] = 1
        self.total += 1

    # get the number of total words we've trained on
    def get_training_count(self):  # returns integer
        return self.total

    # get the number of times we've seen this word (0 if never)
    def get_word_count(self, word):  # string. returns integer
        return self.word_to_count[word]

    # recompute the word probabilities and prefix mapping
    def build(self):
        for word in self.word_to_count:
            cur_prob = float(self.word_to_count[word] / self.total)
            new_entry = DictEntry(word, cur_prob)

            self.prefix_to_entry[word] = new_entry
            for i in range(1, len(word)): # Loop all possible "prefixes"
                '''
                I don't understand a probability could be computed for a prefix (since it's not a proper key in the map)
                This is where I'm stuck for this assignment. Turning in a partial solution instead 
                '''
                if(float(self.word_to_count[self.get_best(word[:i])]) / self.total > cur_prob):
                    pass


    # return the most likely DictEntry object given a word prefix
    def get_best(self, prefix):  # returns type DictEntry
        try:
            return self.prefix_to_entry[prefix]
        except KeyError:
            return "whale" # test word to return

t = WordPredictor()

t.train("mobydick.txt")
t.train("moby_start.txt")
t.train("moby_end.txt")
#t.train("wiki_200k.txt")

t.build()



