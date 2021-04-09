/***************************************************************
 * File: order.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Order class.
 ***************************************************************/
#include "order.h"

// constructors
Order :: Order()
{
   quantity = 0;
}
Order :: Order(Product product,
               int quantity,
               Customer customer)
{
   setCustomer(customer);
   setProduct(product);
   setQuantity(quantity);
}

// Put your the method bodies for your order class here

/***************************************************************
 * DISPLAY CUSTOMER INFO
 * Display customer info (name, street, city, state, zip)
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
void Order :: displayShippingLabel() const
{
   cout << customer.getName() << endl
        << customer.getAddress().getStreet() << endl
        << customer.getAddress().getCity() << ", " << customer.getAddress().getState() << " " << customer.getAddress().getZip() << endl;
}

/***************************************************************
 * DISPLAY ORDER INFO
 * Display order info (customer name, product name, total price)
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
void Order :: displayInformation() const
{
   cout << customer.getName() << endl
        << product.getName() << endl
        << "Total Price: $" << getTotalPrice() << endl;
}

/***************************************************************
 * GET CUSTOMER DATA
 * Get the customer data
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
Customer Order :: getCustomer() const
{
   return customer;
}

/***************************************************************
 * GET PRODUCT DATA
 * Get the product data
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
Product Order :: getProduct() const
{
   return product;
}

/***************************************************************
 * GET ORDER QUANTITY
 * Get the order quantity
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
int Order :: getQuantity() const
{
   return quantity;
}

/***************************************************************
 * GET ADDRESS ZIP
 * Get the address zip
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
string Order :: getShippingZip() const
{
   return customer.getAddress().getZip();
}

/***************************************************************
 * GET PRODUCT TOTAL PRICE
 * Get the product total price
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
float Order :: getTotalPrice() const
{
   return product.getTotalPrice() * quantity;
}

/***************************************************************
 * SET CUSTOMER DATA
 * Set the customer data
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
void Order :: setCustomer(Customer customer)
{
   this -> customer = customer;
}

/***************************************************************
 * SET PRODUCT DATA
 * Set the product data
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
void Order :: setProduct(Product product)
{
   this -> product = product;
}

/***************************************************************
 * SET ORDER QUANTITY
 * Set the order quantity
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 *        Product [class] - name, description, basePrice, weight
 ***************************************************************/
void Order :: setQuantity(int quantity)
{
   this -> quantity = quantity;
}
