# minishell

## 📘 Project Overview

**minishell** is a major project from 42 School that consists of creating a simplified UNIX shell, inspired by **bash**.

The program must interpret user input, execute commands, manage environment variables, handle redirections and pipes, and respond correctly to signals, while behaving as closely as possible to a real shell.

As required by the project constraints, the use of standard C library functions was restricted.  
Only functions previously re-implemented in the **libft** project were allowed.

This project was developed as a **group project**, in collaboration with  
**[mkoyomba](https://github.com/mkoyamba)**.

---

## ⚙️ Compilation

Use the provided Makefile to build and manage the project:

- `make`  
  Compiles the project.

- `make clean`  
  Removes object files while keeping the executable.

- `make fclean`  
  Removes object files and the executable.

- `make re`  
  Removes all compiled files and recompiles the project from scratch.

---

## ▶️ Usage

Launch the shell with:

```bash
./minishell
```

Once started, minishell behaves like a standard shell, supporting:

- Command execution via PATH resolution

- Built-in commands

- Pipes and redirections

- Environment variables

- Quotes and signal handling

---

## 🧠 Notes

- Custom command parser and executor.

- Proper signal handling (Ctrl-C, Ctrl-D, Ctrl-\).

- Close adherence to bash behavior where required.

- Fully compliant with the 42 Norm.
