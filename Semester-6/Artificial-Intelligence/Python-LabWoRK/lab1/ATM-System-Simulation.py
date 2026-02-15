class ATM:
    def __init__(self, name, account_number, balance, address, contact):
        self.name = name
        self.account_number = account_number
        self.balance = balance
        self.address = address
        self.contact = contact

    # Check Balance
    def check_balance(self):
        print(f"Current Balance: {self.balance}")

    # Deposit Money
    def deposit(self, amount):
        self.balance += amount
        print(f"{amount} deposited successfully.")
        print(f"Updated Balance: {self.balance}")

    # Withdraw Money
    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
            print(f"{amount} withdrawn successfully.")
            print(f"Remaining Balance: {self.balance}")
        else:
            print("Insufficient balance!")

    # Display Account Details
    def display_details(self):
        print("\n--- Account Details ---")
        print("Name:", self.name)
        print("Account Number:", self.account_number)
        print("Address:", self.address)
        print("Contact:", self.contact)
        print("Balance:", self.balance)


# Create 3 account objects
account1 = ATM("Alice", "1001", 5000, "Lahore", "03001234567")
account2 = ATM("Bob", "1002", 8000, "Islamabad", "03111234567")
account3 = ATM("Charlie", "1003", 3000, "Karachi", "03221234567")


# Test Functionality

# Account 1
account1.display_details()
account1.deposit(1000)
account1.withdraw(2000)
account1.check_balance()

# Account 2
account2.display_details()
account2.withdraw(9000)   # Insufficient balance test

# Account 3
account3.display_details()
account3.deposit(500)
account3.check_balance()
