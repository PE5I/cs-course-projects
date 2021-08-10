from math import sqrt

'''
Pesi Taototo
Cpts 215 - MA1
Primality
'''

def is_prime(num):
    '''
    Returns True if input is prime, otherwise returns False
    '''
    square_root = sqrt(num)
    
    # 0 and 1 is not a prime number
    if(num == 0 or num == 1):
        return False
    
    i = 2
    while (i <= square_root):
        # Once we know num is divisible by an integer > 2, we return False
        if (num % i == 0):
            return False
        i += 1
    # While loop fails to find a divisor greater than 2 for num
    return True

def sum_primes(upper_integer):
    '''
    Sums prime integers from 2 up to some integer M (upper_integer)
    '''
    sum_of_primes = 0
    i = 2
    while(i <= upper_integer):
        if(is_prime(i)):
           sum_of_primes += i
        i += 1
    
    return sum_of_primes
    
# Gets user input for testing an integer >= 2 for primality
user_integer = int(input("Please enter an integer >= 2: "))
if(is_prime(user_integer)):
    print("%d is prime" %(user_integer))
else:
    print("%d is not prime" %(user_integer))

# Gets user input for the Bonus problem
M = int(input("Enter an upper integer M such that all primes from 2 to M will be summed: "))
print("The sum of all primes between 2 and %d: %d" %(M, sum_primes(M)))