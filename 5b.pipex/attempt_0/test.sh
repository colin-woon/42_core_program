#!/bin/bash

./pipex file1 cmd1 cmd2

./pipex non_existent_file cmd1 cmd2 file2

touch file1
./pipex file1 cmd1 cmd2 /invalid_path/file2

./pipex file1 invalid_command cmd2 file2

rm -rf file1
rm -rf file2
