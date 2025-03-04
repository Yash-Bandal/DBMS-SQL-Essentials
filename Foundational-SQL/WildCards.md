# SQL Wildcards in WHERE Clause

Wildcards in SQL are special characters used with the `LIKE` operator in the `WHERE` clause to filter results based on patterns rather than exact values.

## 📌 Common Wildcards

| Wildcard | Description | Example |
|----------|-------------|---------|
| `%` (Percent) | Matches **zero or more** characters | `WHERE name LIKE 'A%'` → Names starting with "A" |
| `_` (Underscore) | Matches **exactly one** character | `WHERE name LIKE 'J_hn'` → Matches "John", "Jahn" |
| `[ ]` (Brackets) | Matches **any single** character inside the brackets | `WHERE name LIKE 'M[ae]ry'` → Matches "Mary" or "Mery" |
| `[^ ]` (Caret inside brackets) | Matches **any single character NOT in the brackets** | `WHERE name LIKE 'M[^ae]ry'` → Matches "Miry" but NOT "Mary" or "Mery" |
| `-` (Hyphen inside brackets) | Matches a **range of characters** | `WHERE name LIKE '[C-F]%'` → Names starting with C, D, E, or F |

## 🚀 Example Queries

### 1️⃣ Find names starting with "J"
```sql
SELECT * FROM users WHERE name LIKE 'J%';
```
✅ Matches: `"John"`, `"Jake"`, `"James"`

### 2️⃣ Find names ending with "son"
```sql
SELECT * FROM users WHERE name LIKE '%son';
```
✅ Matches: `"Anderson"`, `"Jackson"`

### 3️⃣ Find names containing "ar" in the middle
```sql
SELECT * FROM users WHERE name LIKE '%ar%';
```
✅ Matches: `"Harry"`, `"Marry"`, `"Carson"`

### 4️⃣ Find names with exactly 4 letters, starting with "A" and ending with "n"
```sql
SELECT * FROM users WHERE name LIKE 'A_n';
```
✅ Matches: `"Ann"`, `"Arn"` (but **not** `"Aaron"` as it has 5 letters)

### 5️⃣ Find names starting with "A" to "D"
```sql
SELECT * FROM users WHERE name LIKE '[A-D]%';
```
✅ Matches: `"Alice"`, `"Bob"`, `"Charlie"`

### 6️⃣ Find names **not** starting with "A" or "B"
```sql
SELECT * FROM users WHERE name LIKE '[^A-B]%';
```
✅ Matches: `"Charlie"`, `"David"` (but **not** `"Alice"` or `"Bob"`)

## ⚡ Best Practices
✔ Use wildcards **only when necessary** as they can slow down queries. 🔥
✔ Avoid `%` at the **start** of a pattern (`'%abc'`) as it makes indexing inefficient.
✔ Combine wildcards with **other conditions** for optimized queries.

---

