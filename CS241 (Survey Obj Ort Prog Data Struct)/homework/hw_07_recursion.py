def fib(n = 0):
    if n <= 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

def main():
    index = fib(int(input('Enter a Fibonacci index: ')))
    print(f'The Fibonacci number is: {index}')

if __name__ == "__main__":
    main()
