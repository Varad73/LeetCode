pragma solidity ^0.8.0;

contract StudentData {

    struct Student {
        uint256 id;
        string name;
        uint8 age;
        string course;
    }

    Student[] public students;

    mapping(uint256 => bool) public studentExists;

    event StudentAdded(uint256 indexed id, string name, uint8 age, string course);
    event EtherReceived(address indexed sender, uint256 amount);
    event FallbackTriggered(address indexed sender, uint256 amount, bytes data);

    function addStudent(
        uint256 _id, 
        string memory _name, 
        uint8 _age, 
        string memory _course
    ) public {
        require(!studentExists[_id], "Student ID already exists!");
        
        Student memory newStudent = Student({
            id: _id,
            name: _name,
            age: _age,
            course: _course
        });

        students.push(newStudent);
        studentExists[_id] = true;

        emit StudentAdded(_id, _name, _age, _course);
    }

    function getStudentCount() public view returns (uint256) {
        return students.length;
    }

    function getStudentByIndex(uint256 index) public view returns (
        uint256 id, 
        string memory name, 
        uint8 age, 
        string memory course
    ) {
        require(index < students.length, "Index out of bounds!");
        Student memory s = students[index];
        return (s.id, s.name, s.age, s.course);
    }

    receive() external payable {
        emit EtherReceived(msg.sender, msg.value);
    }

    fallback() external payable {
        emit FallbackTriggered(msg.sender, msg.value, msg.data);
    }
    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }
}