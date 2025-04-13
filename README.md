### 🕵️‍♂️ Meine_Spy_Syscall

A custom Linux syscall that retrieves runtime information about a process by name — including its PID, UID, and the CPU it's running on.
Perfect for lightweight monitoring, debugging, or validating app deployments during testing!

**✨ Features**

🔎 spy_info syscall lets you:

    Search for a process by name (e.g., "bash", "firefox", "my_service")

    Retrieve:

        🧠 PID — Process ID

        👤 UID — User ID running the process

        🖥️ CPU — The core where the process is currently scheduled

**📦 Use Case**

This syscall is especially handy when:

    You're deploying/testing applications and want to confirm they're running correctly

    You need a quick sanity check on live processes

    You're building custom system-level tools or lightweight introspection scripts

**🔧 Spy Info – User App**

The included user-space tool demonstrates how to call the spy_info syscall and display the results in a human-friendly format.
🛠️ Usage
```bash
    ./spyinfo <process_name>
```
Example:
```bash
    ./spyinfo bash
```
**📤 Output**

🔍 Process Name: bash
🧠 PID: 1234
👤 UID: 1000
🖥️ CPU: 3

**📁 File Structure**
```bash
    .
    ├── spy_syscall/         
    │   └── spy_syscall.c
    ├── spy_syscall_user/            
    │   └── spyinfo.c
    └── README.md
```

:white_square_button: **TO_DO:**
- [X] Syscall functionality developement
- [X] User app developement
- [ ] Registering Meine_Spy_Syscall in the kernel syscall table
- [ ] Writing a makefile for the project
- [ ] Creating a kernel module version for testing
- [ ] Creating a VM for testing
