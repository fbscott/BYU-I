class Order:
    """Order Constructor"""
    def __init__(self):
        self.id = ""
        self.products = []

    def get_subtotal(self):
        """
        iterates through products list
        adds each product's total price to the subtotal
        """
        # start at 0
        subtotal = 0

        for product in self.products:
            # update the subtotal for each product
            subtotal += product.get_total_price()

        return subtotal

    def get_tax(self):
        """calculate tax based on hardcoded value"""
        return self.get_subtotal() * 0.065

    def get_total(self):
        """calculate total including tax"""
        return self.get_subtotal() + self.get_tax()

    def add_product(self, product):
        """add additional products to the order"""
        self.products.append(product)

    def display_receipt(self):
        """display order details"""
        print(f"Order: {self.id}")

        # display each products details
        for product in self.products:
            product.display()

        print("Subtotal: ${:.2f}".format(self.get_subtotal()))
        print("Tax: ${:.2f}".format(self.get_tax()))
        print("Total: ${:.2f}".format(self.get_total()))
