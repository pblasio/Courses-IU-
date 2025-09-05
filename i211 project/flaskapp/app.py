# Copyright © 2023-2024, Indiana University
# BSD 3-Clause License

from flask import Flask, render_template, url_for, redirect, request
import csv
app = Flask(__name__)

def load_items():
    with open('items.csv', encoding='UTF-8-sig') as csvfile:
        contents = csv.DictReader(csvfile)
        items = {row['item_slug']: {
            'item_slug': row['item_slug'],
            'name': row['name'],
            'cost': row['cost'], 
            'image_path': row['image_path'] 

            } for row in contents}
    return items 

def load_customer():
    with open('Customer.csv', encoding='UTF-8-sig') as csvfile:
        contents = csv.DictReader(csvfile)
        customers = [ {
            'name': row['name'],
            'email': row['email'], 
            'phone': row['phone'] 

            } for row in contents]
    return customers 

def load_order():
    with open('Orders.csv', encoding='UTF-8-sig') as csvfile:
        contents = csv.DictReader(csvfile)
        orders = {row['order_slug']: {
            'order_slug':row['order_slug'],
            'order_id': row['order_id'],
            'cust_name': row['cust_name'], 
            'item_name': row['item_name'] 

            } for row in contents}
    return orders 

# def sluggify_customer(slug: str) -> str:
#     return slug.replace(" ", "-").replace("'", "")

def set_add_customers(customers):
    with open('Customer.csv', mode='w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=[
            'name', 'email', 'phone'])
        writer.writeheader()
        writer.writerow(customers)







@app.route("/")
def render_index(): 
    items=load_items()

    return render_template("index.html", items=items) 

@app.route("/items/")
def render_items(): 
    items = load_items()
    return render_template("items.html", items=items) 

@app.route("/customers/")
def render_customers(): 
    customers = load_customer() 

    return render_template("customers.html", customers=customers) 

@app.route("/orders/")
def render_orders():
    orders = load_order()
    return render_template("orders.html", orders=orders) 

#Get help for this part 
@app.route("/orders/<order_id>")
def render_orderid(order_id):
    order = load_order() 
    print(order) 
    for x in order:
       if x == order_id: 
           return render_template("order.html", order_id=order[x])
    
#  add customer route
@app.route('/customer/add/', methods=['GET', 'POST'])
def add_new_customer():
    if request.method == "POST":
        #get form data
        name = request.form['name']
        email = request.form['email']
        phone = request.form['phone'] 


        new_customer = {
            'name': name,
            'email' : email, 
            'phone' : phone }
        #load csv
        customers = load_customer() 
        #add csv get this check if error 
        customers["name"] = new_customer
        #set csv
        set_add_customers(customers)

        # Processes data then goes back to customer page
        return redirect(url_for('render_customers'))
    else:
        return render_template("customer_form.html")








 # edit customer route







 # add item route









 # edit item route
