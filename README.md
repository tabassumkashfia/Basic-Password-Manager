# 🔐 DroidPass: Your Ultimate Password Management Solution

**DroidPass** is a simple console-based password manager written in **C**. It allows users to store and retrieve account credentials, check password strength, and manage multiple accounts efficiently.

## 🧰 Features

- ➕ Add account credentials (username, password, Gmail, and app name)
- 🔍 Retrieve saved passwords by account name
- 📊 Evaluate password strength based on various security criteria
- 📃 Display all saved accounts in a formatted table
- 📦 Supports up to 10 accounts

## 🛠 Technologies Used

- C Programming Language
- Standard Libraries: `stdio.h`, `string.h`, `ctype.h`, `stdlib.h`

## 🔐 Password Strength Criteria

A password is evaluated on the following:
- Contains at least one **uppercase letter**
- Contains at least one **lowercase letter**
- Contains at least one **digit**
- Contains at least one **special character**
- **Does not** include obvious/common passwords (like `password`, `12345678`, etc.)
- **Does not** contain a 5-character **sequence** (like `abcde` or `54321`)
- Length is between **8 and 64** characters

### Strength Levels:
- **Very Weak** (less than 4 criteria met)
- **Weak** (4 criteria)
- **Medium** (5 criteria)
- **Strong** (6 or more criteria)


Use the menu:

1 Add a new account

2 Retrieve a password using the account name

3 Check the strength of any password

4 View all saved accounts

5 Exit the application

📌 Limitations
Only 10 accounts can be stored at once.

No encryption or file storage (data is lost after the program exits).

Console-based UI.

🧑‍💻 Author
Kashfia Tabassum
📧 Email: tabassumkashfia707@gmail.com


