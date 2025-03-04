# CASCADE in SQL

The **CASCADE** option in SQL is used with **foreign key constraints** to automatically **propagate changes** (DELETE or UPDATE) from a parent table to a child table. It helps maintain **referential integrity** in a relational database.

---

## **🚀 Types of CASCADE Actions**

| **CASCADE Option**      | **Description** |
|-------------------------|----------------|
| `ON DELETE CASCADE`    | If a row in the parent table is **deleted**, all matching rows in the child table are also **deleted automatically**. |
| `ON UPDATE CASCADE`    | If a **primary key** in the parent table is **updated**, all corresponding foreign key values in the child table are **updated automatically**. |

---

## **📌 Example: CASCADE in Action**

### **1️⃣ Create Parent Table (`departments`)**
```sql
CREATE TABLE departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);
```

### **2️⃣ Create Child Table (`employees`) with Foreign Key & CASCADE**
```sql
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    dept_id INT,
    FOREIGN KEY (dept_id) 
        REFERENCES departments(dept_id) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE
);
```

---

## **🔥 How CASCADE Works?**

### **🛑 ON DELETE CASCADE Example**  
#### **Delete a department (Parent Table)**
```sql
DELETE FROM departments WHERE dept_id = 1;
```
✅ **Result:** All employees with `dept_id = 1` in the `employees` table will be **deleted automatically**.

---

### **✏️ ON UPDATE CASCADE Example**  
#### **Update department ID in Parent Table**
```sql
UPDATE departments SET dept_id = 10 WHERE dept_id = 1;
```
✅ **Result:** All employees with `dept_id = 1` in the `employees` table will have their `dept_id` **updated to 10**.

---

## **⚠️ When to Use CASCADE?**  
- ✔ **Use `ON DELETE CASCADE`** when deleting a parent should also remove related child records (e.g., deleting an order should remove all its order items).  
- ✔ **Use `ON UPDATE CASCADE`** when you need **consistent foreign key values** if a primary key is updated.  
- ❌ Avoid **CASCADE** if accidental deletions/updates could remove critical data.  

---

## **📝 Best Practices**
- Always **double-check** before applying `ON DELETE CASCADE` (especially for critical data).  
- Use **transactions** (`BEGIN TRANSACTION`) for safer updates/deletes.  
- If unsure, prefer **`ON DELETE SET NULL`** to keep child records but remove references.  

