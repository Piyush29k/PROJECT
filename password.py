import string
import secrets

def generate_password(length=12, use_upper=True, use_lower=True, use_digits=True, use_symbols=True):
    characters = ''
    if use_upper:
        characters += string.ascii_uppercase
    if use_lower:
        characters += string.ascii_lowercase
    if use_digits:
        characters += string.digits
    if use_symbols:
        characters += string.punctuation

    if not characters:
        raise ValueError("At least one character set must be selected!")

    password = ''.join(secrets.choice(characters) for _ in range(length))
    return password

def main():
    print("=== Secure Password Generator ===")
    try:
        length = int(input("Enter password length (default 12): ") or 12)
    except ValueError:
        print("Invalid input. Using default length 12.")
        length = 12

    upper = input("Include uppercase letters? (y/n): ").lower() == 'y'
    lower = input("Include lowercase letters? (y/n): ").lower() == 'y'
    digits = input("Include numbers? (y/n): ").lower() == 'y'
    symbols = input("Include symbols? (y/n): ").lower() == 'y'

    try:
        password = generate_password(length, upper, lower, digits, symbols)
        print(f"\nGenerated Password: {password}")
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
