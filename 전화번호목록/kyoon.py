def diff(a, b):
    alen = len(a)
    blen = len(b)
    l = alen if alen < blen else blen
    for i in range(l):
        if a[i] != b[i]:
            return False
    return True

def solution(phone_book):
    phone_book.sort()
    l = len(phone_book)
    for i in range(l-1):
        if diff(phone_book[i], phone_book[i+1]):
            return False
    return True

phone_book = ["119", "97674223", "1195524421"]
print(solution(phone_book))