# Infotainment-Project
We implemented an infotainment system based on Raspberry Pi, focusing on embedded C software development, integrating peripheral devices, and optimizing system performance to deliver a seamless and interactive user experience.

```markdown
# 🚗 Infotainment System with VSOME/IP & Qt

An in-vehicle infotainment system using **VSOME/IP** for inter-module communication and **Qt** for the user interface. The system demonstrates a **server-client architecture** where the server sends **speed data** and the client displays it using a **gauge UI**.

---

## 📋 **Table of Contents**
- [Project Overview](#project-overview)
- [Features](#features)
- [Architecture](#architecture)
- [Getting Started](#getting-started)
- [Build & Run](#build--run)
- [UI Preview](#ui-preview)
- [Technologies Used](#technologies-used)
- [Folder Structure](#folder-structure)
- [Contributing](#contributing)
- [License](#license)

---

## 📖 **Project Overview**

This project uses:
- **VSOME/IP** for data communication between modules.
- **Qt & QML** to create an intuitive user interface.
- A **server** module that simulates CAN data transmission.
- A **client** module that receives and visualizes data.

Use cases include **instrument clusters**, **head units**, and **diagnostic systems** in automotive applications.

---

## ✨ **Features**

- **Real-time data transmission** using VSOME/IP.
- **Modular architecture** allowing easy addition of new services.
- **Qt QML Gauge UI** to display data dynamically.
- Supports **local** and **network-based communication**.

---

## 🧠 **Architecture**

```plaintext
┌────────────┐          ┌────────────┐
│  VSOME/IP  │ Ethernet │  VSOME/IP  │
│  Server    │─────────▶│  Client    │
│  (CAN Data)│          │  (UI)      │
└────────────┘          └────────────┘
```

1. **Server Module:** Sends simulated speed data.
2. **Client Module:** Receives data and updates the UI.
3. **QML UI:** Displays speed data using a Gauge component.

---

## 🚀 **Getting Started**

### 🔧 **Prerequisites**

- **C++17** or later
- **Qt 6.x** (`qtbase`, `qtdeclarative`, `qtcreator`)
- **VSOME/IP** (`libvsomeip3`, `boost`)

```bash
# Install required packages (Ubuntu/Debian)
sudo apt update
sudo apt install build-essential cmake git libboost-all-dev \
                 qt6-base-dev qt6-declarative-dev qtcreator -y
```

### 📦 **Cloning the Repository**

```bash
git clone https://github.com/username/infotainment-system.git
cd infotainment-system
```

---

## 🛠 **Build & Run**

### 🏗️ **Building the Project**

```bash
mkdir build && cd build
cmake ..
make
```

### 🚦 **Running the Server & Client**

1. **Run the VSOME/IP Server:**
```bash
export VSOMEIP_CONFIGURATION=../config/application.json
export VSOMEIP_APPLICATION_NAME=DataServer
./server
```

2. **Run the VSOME/IP Client:**
```bash
export VSOMEIP_APPLICATION_NAME=DataClient
./client
```

---

## 🎨 **UI Preview**

![UI Screenshot](resources/ui_preview.png)

The **Gauge UI** displays speed data in real-time as it is received from the server.

---

## 🔍 **Technologies Used**

- **C++ & VSOME/IP:** For high-performance data communication.
- **Qt & QML:** To build a dynamic and responsive user interface.
- **CMake:** Build automation.

---

## 📁 **Folder Structure**

```plaintext
infotainment-system/
├─ src/                     # C++ source files
│    ├─ server/             # VSOME/IP server module
│    ├─ client/             # VSOME/IP client module
│    ├─ common/             # Common utilities (e.g., Constants.hpp)
│    └─ CMakeLists.txt      # Source code CMake configuration
├─ ui/                      # QML UI files
│    └─ main.qml
├─ config/                  # VSOME/IP configuration files
│    └─ application.json
├─ resources/               # Images, icons, assets
├─ CMakeLists.txt           # Main CMake configuration
└─ README.md                # Project documentation
```

---

## 🤝 **Contributing**

Contributions are welcome! Please follow these steps:

1. **Fork the repository**
2. **Create a new branch:** `git checkout -b feature-branch`
3. **Make your changes and commit:** `git commit -m "Add new feature"`
4. **Push to the branch:** `git push origin feature-branch`
5. **Create a Pull Request**

---

## 📜 **License**

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
```

---

# ✅ **README 작성 시 팁**

1. **간결하게, 그러나 충분히 설명**하세요.  
2. **이미지나 GIF**를 추가해 **UI나 결과물**을 보여주는 것이 좋습니다.  
3. **빌드 및 실행 방법**을 최대한 **따라하기 쉽게** 작성하세요.  
4. **기여 방법**을 적어두면 **오픈소스 참여자**가 쉽게 접근할 수 있습니다.  
5. **기술 스택**을 명확히 명시하면 좋습니다.

---

# 💡 **추가하면 좋은 내용**

- **Troubleshooting** 섹션: 자주 발생하는 문제와 해결 방법.  
- **FAQ**: 프로젝트 사용 시 발생할 수 있는 질문들.  
- **Release Notes**: 주요 업데이트나 기능 추가 시 기록.

---
