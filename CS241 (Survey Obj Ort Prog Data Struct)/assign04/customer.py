class Customer:
    """Customer Constructor"""
    def __init__(self):
        self.id = ""
        self.name = ""
        self.orders = []

    def get_order_count(self):
        return len(self.orders)

    def get_total(self):
        """
        iterates through orders list
        adds each order's total to the grand total
        """
        # start at 0
        total = 0

        for order in self.orders:
            # update the total for each order
            total += order.get_total()

        return total

    def add_order(self, order):
        """add additional orders for this customer"""
        self.orders.append(order)

    def display_summary(self):
        """display customer summary"""
        print(f"Summary for customer '{self.id}':")
        print(f"Name: {self.name}")
        print(f"Orders: {self.get_order_count()}")
        print("Total: ${:.2f}".format(self.get_total()))

    def display_receipts(self):
        """display receipt details"""
        print(f"Detailed receipts for customer '{self.id}':")
        print(f"Name: {self.name}")

        for order in self.orders:
            # display each order's details
            print()
            order.display_receipt()
