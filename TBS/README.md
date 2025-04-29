# Telecom Billing System

## Description

This is a simple command-line Telecom Billing System implemented in C. It manages customer information, tariff plans, and generates bills. It also demonstrates the use of fundamental data structures: linked lists, binary trees, and queues.  The system persists data to a text file (`telecom_db.txt`).

## Features

* **Customer Management:**
    * Add new customers with their details (name, phone number, plan).
    * Remove existing customers.
    * Display all customer information.
    * Search for customers by name.
    * Update customer details (name, phone number, plan, call duration, bill amount).
    * Filter customers by their selected plan.
* **Plan Management:**
    * Display available tariff plans.
    * Add new tariff plans.
* **Billing:**
    * Calculate and update bills for individual customers based on call duration.
    * Generate bills for all customers.
* **Data Storage:**
    * Saves customer and plan data to a text file (`telecom_db.txt`) for persistence.
    * Loads data from the text file on startup.
* **Data Structures:**
    * Demonstrates the use of linked lists, binary trees, and queues by displaying customer data in these structures.
* **Sorting:**
    * Sort customers alphabetically by name.

## File Structure

The project is organized into the following files:
```
telecom_billing/
├── main.c           # Main program file
├── customer.h       # Header file for customer related functions and structures
├── customer.c       # Source file for customer management functions
├── plan.h           # Header file for plan related functions and structures
├── plan.c           # Source file for plan management functions
├── billing.h        # Header file for billing functions
├── billing.c        # Source file for billing functions
├── database.h       # Header file for database interaction functions
├── database.c       # Source file for database interaction functions (file I/O)
├── data_structures.h # Header file for data structure definitions
├── data_structures.c # Source file for data structure implementations
├── utils.h          # Header file for utility functions (e.g., input validation)
└── utils.c          # Source file for utility functions
```
## How to Compile and Run

1.  **Ensure you have a C compiler (like GCC) installed.**

2.  **Navigate to the `telecom_billing` directory in your terminal.**

3.  **Compile the code:**

    ```bash
    gcc main.c customer.c plan.c billing.c database.c data_structures.c utils.c -o telecom_billing
    ```

4.  **Run the executable:**

    ```bash
    ./telecom_billing
    ```

## Usage

When you run the program, you will be presented with a menu of options.  Follow the on-screen instructions to interact with the system.  The options are:

1.  **Add Customer:** Add a new customer to the system.
2.  **Remove Customer:** Remove an existing customer.
3.  **Display Customers:** Show the details of all customers.
4.  **Calculate Bill:** Calculate and update the bill for a specific customer.
5.  **Search Customer:** Search for a customer by name.
6.  **Sort Customers:** Sort the customers alphabetically by name.
7.  **Display Plans:** Show the available tariff plans.
8.  **Add New Plan:** Add a new tariff plan to the system.
9.  **Generate Bills:** Generate bills for all customers.
10. **Update Customer:** Update customer information.
11. **Filter Customers by Plan:** Display customers who have subscribed to a specific plan.
12. **Display Data Structures:** Displays the customer data organized as a Linked List, Binary Tree, and Queue.  Also checks if the Binary Tree is Full or Complete.
0.  **Exit:** Exit the program.

## Data Storage

The system uses a simple text file named `telecom_db.txt` to store data.  The format of this file is as follows:
```
Plans
Plan1_Name Rate1 FreeMinutes1 DataLimit1
Plan2_Name Rate2 FreeMinutes2 DataLimit2
...
Customers
Customer1_Name Phone1 CallDuration1 BillAmount1 Plan1_Name Plan1_Rate Plan1_FreeMinutes Plan1_DataLimit
Customer2_Name Phone2 CallDuration2 BillAmount2 Plan2_Name Plan2_Rate Plan2_FreeMinutes Plan2_DataLimit
...
```
**Note:** The database file is automatically created if it doesn't exist.  Do not manually edit this file, as it may corrupt the data.

## Assumptions

* Phone numbers are 10 digits.
* Plan prices are calculated monthly (assuming 30 days in a month).
* The system has a maximum number of customers (`MAX_CUSTOMERS`) and plans (`MAX_PLANS`) defined in the code.

## Future Enhancements

* Implement data usage tracking and billing.
* Add support for more complex billing scenarios (e.g., different rates for peak/off-peak hours).
* Develop a more user-friendly interface (e.g., a graphical user interface).
* Implement more robust error handling.
* Use a more robust database system (e.g., SQLite) instead of a simple text file.
