def solution(numbers):
    answer = 0
    numbers = list(numbers)
    primes = set([])
    check = [0 for _ in range(len(numbers))]

    def is_prime_number(num):
        num = int(num)
        if num <= 1:
            return False
        for i in range(2, num):
            if i > num**(1/2):
                break
            if num % i == 0:
                return False
        return True

    def make_prime(numbers, num, check, length):
        if len(num) == length:
            if is_prime_number(num):
                primes.add(int(num))
            return
        
        for i in range(len(numbers)):
            if check[i] == 1:
                continue
            check[i] = 1
            num += numbers[i]
            make_prime(numbers, num, check, length)
            num = num[0:-1]
            check[i] = 0
    
    for i in range(1, len(numbers) + 1):
        make_prime(numbers, "", [0 for _ in range(len(numbers))], i)
    return len(primes)