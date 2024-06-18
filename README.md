# Minitalk

MiniTalk is a simple client-server program that allows you to send messages between two processes using signals. The server is a program that receives messages and displays them. The client is a program that sends messages to the server.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
- [Running the tests](#running-the-tests)
- [Usage](#usage)
- [Built Using](#built-using)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## About

This project is a part of the School 21 curriculum. The main goal of this project is to learn how to work with signals in Unix systems. The server is a program that receives messages and displays them. The client is a program that sends messages to the server. 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them.

```text
gcc >= 7.5.0
make >= 4.1
```

```bash
sudo apt-get install make
sudo apt-get install gcc
```

### Installing

A step by step series of examples that tell you how to get a development env running.

Clone the repository.

```bash
git clone https://github.com/LudwigAndreas/minitalk.git

cd minitalk
```

Build the project using the makefile

```bash
make
```

Run the server program.

```bash
./server
```

Run the client program.

```bash
./client [server_pid]
```

## Running the tests

Explain how to run the automated tests for this system.

```bash
make test
```

## Usage

The server is a program that receives messages and displays them. The client is a program that sends messages to the server. The client program takes two arguments: the server process ID and the message to send.

```bash
./server
```

```bash
./client [server_pid]
```

After running the server and client programs, you can send messages from the client to the server. The server will display the received messages.

## Built Using

- [C](https://isocpp.org/) - Programming language
- [Make](https://www.gnu.org/software/make/) - Build automation tool
- [Libft](https://github.com/LudwigAndreas/ft_libftprintf) - Custom printf library

## Authors

This project was developed by:

| <img src="https://avatars.githubusercontent.com/u/88089961?v=4" alt="drawing" width="50"/> |[LudwigAndreas](https://github.com/LudwigAndreas)|
| --- | --- |

## Acknowledgements

- [School 21](https://21-school.ru/) - Educational institution
- [42](https://www.42.fr/) - Educational institution

## License

This project is licensed under the School 21 License - see the [LICENSE](LICENSE) file for details.
