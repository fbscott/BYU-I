class Product:
    """Product Constructor"""
    def __init__(self, id, name, price, quantity):
        self.id = id
        self.name = name
        self.price = float(price)
        self.quantity = quantity

    def get_total_price(self):
        """returns total price"""
        return self.price * self.quantity

    def display(self):
        """display product details"""
        # format: Item (qty) - $price
        print("{} ({}) - ${:.2f}".format(self.name, self.quantity, self.get_total_price()))
