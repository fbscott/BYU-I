class Order:
    """Order Constructor"""
    def __init__(self):
        self.id = ""
        self.products = []

    def get_subtotal(self):
        """sums the price of each product and returns it"""
        # start at 0
        subtotal = 0

        for product in self.products:
            # update the subtotal for each product
            subtotal += product.get_total_price()

        return subtotal

    def get_tax(self):
        """calculates and returns the tax based on hardcoded value (6.5%)"""
        return self.get_subtotal() * 0.065

    def get_total(self):
        """calculates and returns a subtotal - including tax"""
        return self.get_subtotal() + self.get_tax()

    def add_product(self, product):
        """add additional products to the order"""
        self.products.append(product)

    def display_receipt(self):
        """display order details"""
        """
        format:
        Order: 1138
        Item1 (qty) - $price
        Item2 (qty) - $price
        etc.
        Subtotal: $subtotal
        Tax: $tax
        Total: $total
        """

        print(f"Order: {self.id}")

        # display each product's details
        for product in self.products:
            product.display()

        print("Subtotal: ${:.2f}".format(self.get_subtotal()))
        print("Tax: ${:.2f}".format(self.get_tax()))
        print("Total: ${:.2f}".format(self.get_total()))
