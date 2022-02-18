def solution(nums):
    def isPrime(num):
        for i in range(2, num):
            if num % i == 0:
                return False
        return True

    def recur(cnt, idx, nums, res):
        if cnt == 3 or idx >= len(nums):
            if cnt == 3 and isPrime(res):
                primes.append(res)
            return
        recur(cnt, idx + 1, nums, res)
        res += nums[idx]
        recur(cnt + 1, idx + 1, nums, res)

    primes = []
    recur(0, 0, nums, 0)
    return len(primes)