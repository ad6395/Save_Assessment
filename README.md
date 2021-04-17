# Save_Assessment

The two APIs for detecting fraud.

First API detects fraud based on abnormality in the pattern of transactions. It takes an average of all tranasaction and detects the highest transaction done by the user.
The API then checks the ration between average transaction and highest transaction and if the ratio is < 0.3, it is considered as fraud.


Second API detects fraud by comparing the User's primmary location and the location as which the transaction occured. If the locations do not match, then the API concludes transaction as fraud.


# MySQL Database.

The transactions table in the database required data cleaning for segregating the state names from merchant_description column. This was required for designing the second API.
Data cleaning was done using Python.
