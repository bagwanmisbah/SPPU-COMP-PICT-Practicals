// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentDatabase {

    struct Student {
        uint studentId;
        string name;
        uint8 grade;
    }

    Student[] public students;

    event ReceivedEther(address sender, uint amount);

    function addStudent(uint _studentId, string memory _name, uint8 _grade) public {
        students.push(Student(_studentId, _name, _grade));
    }

    function getStudent(uint _index) public view returns (uint, string memory, uint8) {
        require(_index < students.length, "Error: Invalid student index.");
        Student storage student = students[_index];
        return (student.studentId, student.name, student.grade);
    }
    
    receive() external payable {
        emit ReceivedEther(msg.sender, msg.value);
    }

    fallback() external {
        revert("Function does not exist.");
    }
}
