from abc import ABC
from abc import abstractmethod

class Employee(ABC):
    def __init__(self, name = ""):
        self.name = name

    @abstractmethod
    def display(self):
        pass

    @abstractmethod
    def get_paycheck(self):
        pass

class HourlyEmployee(Employee):
    def __init__(self, name, wage, hours):
        super().__init__(name)
        self.hourly_wage = wage
        self.hours = hours

    def display(self):
        print(f"{self.name} - ${self.hourly_wage}/hour")

    def get_paycheck(self):
        print(f"Weekly Paycheck: ${self.hourly_wage * self.hours}\n")

class SalaryEmployee(Employee):
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary

    def display(self):
        print(f"{self.name} - ${self.salary}/year")

    def get_paycheck(self):
        print(f"Bi-weekly Paycheck: ${self.salary / 24}\n")

def main():
    employees = []
    command = ""

    while command != "q":
        command = input("Enter 'h' (hourly), 's' (salary) or 'q' to quit: ")

        if command == 'h':
            name = input("Name: ")
            hourly_rate = int(input("Hourly Rate: "))
            number_of_hours = int(input("Hours Worked: "))
            hourlyEmployee = HourlyEmployee(name, hourly_rate, number_of_hours)
            employees.append(hourlyEmployee)

        elif command == 's':
            name = input("Name: ")
            salary = int(input("Salary: "))
            salaryEmployee = SalaryEmployee(name, salary)
            employees.append(salaryEmployee)

    for employee in employees:
        employee.display()
        employee.get_paycheck()

if __name__ == "__main__":
    main()
