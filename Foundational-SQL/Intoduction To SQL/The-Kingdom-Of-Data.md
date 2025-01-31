# The Kingdom of Data: A Story of SQL

In a land where information was scattered across many villages, there lived a young adventurer named Mira. The kingdom had treasures hidden in countless scrolls, books, and ledgers, each one containing precious knowledge. The problem? No one knew how to find the right piece of information at the right time.
Mira was assigned an important mission by the King: she had to uncover valuable insights about the kingdom’s resources. However, the records were not neatly arranged, and the scrolls were stored in various places — in libraries, workshops, and even under the trees in the royal gardens. The task seemed impossible.
But the wise Wizard Oracle, who lived atop the Great Mountain, had a solution. "Mira," he said, "you need the power of SQL, the magical language that can sort, filter, and organize all this knowledge into a map you can easily follow."
Mira, intrigued, traveled to the Wizard Oracle and learned about the magic of SQL. "Let me show you," the Wizard said, "how SQL can unlock the kingdom’s secrets."

## Spells of Queries

### The CREATE TABLE Charm 
In the Kingdom of Data, Mira was tasked with designing a new KingdomInventory table. To do so, she needed to choose the right data types for each column to ensure the data was stored efficiently and accurately. The Wizard Oracle guided her through this process.

```sql
CREATE TABLE KingdomInventory (
    -- Text-based columns
    TreasureID INT PRIMARY KEY,               -- Integer type for IDs (unique identifier)
    Name VARCHAR(100),                         -- Variable-length text (up to 100 characters)
    Description TEXT,                          -- Longer text (e.g., full descriptions)
    
    -- Numeric-based columns
    Value DECIMAL(10, 2),                      -- Numeric value with precision (10 digits total, 2 after the decimal)
    Weight FLOAT,                              -- Floating point number (useful for values that require decimals)
    Quantity INT DEFAULT 1,                    -- Integer column with a default value
    
    -- Date and time columns
    DiscoveryDate DATE,                        -- Date format (YYYY-MM-DD)
    LastUpdated TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- Timestamp format with current time as default
    
    -- Boolean column
    IsActive BOOLEAN DEFAULT TRUE,             -- Boolean (TRUE/FALSE)
    
    -- More complex numeric columns
    Size BIGINT,                               -- Big Integer (useful for very large numbers)
    Price MONEY,                               -- Currency type (depending on DBMS)
    
    -- Binary data column (e.g., image or file)
    TreasureImage BLOB,                        -- Binary Large Object (store image, audio, or other binary data)
    
    -- Geographic data (if needed)
    Location GEOGRAPHY,                        -- Geographic location (e.g., coordinates)
    
    -- JSON-like column for storing semi-structured data
    Attributes JSONB                          -- JSON binary (allows storing structured data, supported in some DBMS)
);

```
### THW SELECT

The first magic Mira learned was the SELECT spell. By casting this spell, Mira could call upon any data she needed from the scrolls. The more specific the request, the more precise her answers.

```sql
SELECT * FROM KingdomResources;
```
The * symbol meant “all,” so it would show every piece of information stored in the "KingdomResources" scroll. But what if Mira only needed the names and values of the kingdom’s treasures? For this, she cast a more focused spell:
```sql
SELECT Name, Value FROM KingdomResources;

```
### THW WHERE

Next, Mira learned the WHERE spell, which allowed her to find specific treasures under certain conditions. If she only wanted to find treasures worth more than 500 gold coins, she cast:
```sql
SELECT Name, Value FROM KingdomResources WHERE Value > 500;
```
This magic filtered out the treasures that didn’t meet the condition, helping Mira focus on what was truly important.

###  ORDER BY
In her journey, Mira needed to sort treasures from the most valuable to the least. The Wizard taught her the ORDER BY charm. With this, Mira could organize treasures by value, ascending or descending.
```sql
SELECT Name, Value FROM KingdomResources ORDER BY Value DESC;

```
This spell would organize the treasures from the most valuable to the least. If Mira wanted to do the opposite, the ascending order (ASC) was just as simple to command.

### INSERT INTO
While exploring the kingdom, Mira discovered a new treasure hidden deep in the forest. The Wizard Oracle showed her how to add this new treasure to the kingdom’s records using the INSERT INTO spell.
```sql
INSERT INTO KingdomResources (Name, Value) VALUES ('Golden Chalice', 1200);
```
Mira carefully cast the spell, and the new treasure appeared in the records.

### UPDATE
As time passed, the value of some treasures increased due to their magical properties. To adjust the records, Mira learned the UPDATE spell.

For example, if the Golden Chalice's value increased to 1500, she would recite:
```sql
UPDATE KingdomResources SET Value = 1500 WHERE Name = 'Golden Chalice';
```

###  The Deletion Curse: DELETE
Finally, Mira learned the power of DELETE. If a treasure was no longer relevant or had been lost in the kingdom, she could remove it from the records.

```sql
DELETE FROM KingdomResources WHERE Name = 'Golden Chalice';
```
But Mira knew that she had to use this magic carefully, for once cast, the data was gone forever.


###  DISTINCT
One day, Mira was tasked with locating all the unique treasures in the kingdom, as some treasures had been listed multiple times due to misreporting. She needed to find only the distinct treasures that had been reported.

"Ah, Mira," the Wizard Oracle said, "you need to cast the DISTINCT spell. It will help you avoid repeating treasures in your results."
```sql
SELECT DISTINCT Name FROM KingdomResources;

```
 Mira was able to gather a list of all unique treasures in the kingdom. No duplicates remained, and the records were clean and clear.

 ###  LIMIT
 The Wizard Oracle explained, “LIMIT allows you to get only a specified number of records, which is especially useful for large datasets."
```sql
SELECT Name, Value FROM KingdomResources LIMIT 5;
```
This spell would give Mira the first five treasures from the kingdom’s records.

### OFFSET
Mira needed to analyze treasures in chunks, where she could examine results in groups rather than all at once. For this, the OFFSET charm came in handy. This charm worked alongside LIMIT, allowing her to skip over a certain number of records before starting to retrieve new ones.

“By using OFFSET,” the Wizard said, “you can page through large datasets in a controlled manner.”

```sql
SELECT Name, Value FROM KingdomResources LIMIT 5 OFFSET 5;

```
This would return the next 5 treasures, starting from the sixth treasure in the records

### Truncate
The Wizard Oracle explained, “Unlike DELETE, which removes rows one by one, TRUNCATE removes all rows instantly and without logging each deletion.
```sql
TRUNCATE TABLE KingdomResources;
```
All the records in the "KingdomResources" table were cleared, 


