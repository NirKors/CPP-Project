# Farmer's Market System

## Overview
This project simulates a trading system in a market where farmers buy and sell products according to their needs. Each farmer owns a farm specializing in the cultivation of a specific type of animal: cows, sheep, or chickens. Consequently, they only raise one type of animal on their farm, which determines the products they produce: cows produce milk, sheep produce wool, and chickens produce eggs.

## Trading
- Each farmer desires a specific product from another farmer: cow farmers buy eggs, sheep farmers buy milk, and chicken farmers buy wool.
- During the trading day, farmers only inform potential buyers (farmers interested in their product) that they have goods for sale before completing the transaction. They do not notify all farmers in the market.
- To implement the communication between farmers, the Observer design pattern is utilized.

## System Management
- Before the trading day begins, new farmers (new farms) join the market according to user demand.
- The system must facilitate the trading process in the market and fulfill all requirements.

## Classes
### Farm
#### Fields (data members)
- **ID:** Farm identifier number.
- **Money:** Amount of money the farm possesses.
- **Animals:** Animals on the farm.
- **Products:** Products available on the farm.

#### Methods
- Default Constructor:
  - Creates a new farm with $10, 3 animals (of the same type the farm specializes in), and no products.
- ID Assignment:
  - Assign the farm's ID based on its creation time. The first farm created in the system receives ID=1, the second ID=2, and so on.
- Farm Output:
  - Prints farm details.

### Market
#### Fields (data members)
- **Year:** Number of years the market has been operating.
- **Farms:** Holds existing farms in the market.

#### Methods
- Default Constructor:
  - Creates a new market with age 0 (year 0) and no farms.
- New Farm Creation:
  - Function to create new farms of any type according to user request.
- Trading Day:
  - Executes trading between farmers.
- Next Year:
  - Moves to the next trading day, creating new farms, updating farm productivity, and executing trading for the new year.

### Animal
This class represents an animal on the farm.
#### Attributes
- **Age:** Age of the animal.
- **Purchase Price:** Purchase price varies for each type of animal: cows cost $10, sheep cost $5, and chickens cost $3.
- **Age of Death:** Age at which the animal dies, depending on its type.

### FarmMarket
This class manages the system's operations and contains the main functions to run the program.

## Error Handling
- Error messages and validation are implemented using exceptions.
- Specific exceptions are defined for negative quantities of animals on a farm.
