//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
import "@openzeppelin/contracts/access/Ownable.sol";

contract UserAge is Ownable {
    mapping (uint => uint) public age;

    modifier olderThan(uint _age, uint _userId) {
        require(age[_userId] >= _age, "User is not old enough");
        _;
    }

    function validationUsers(uint _userId) public view olderThan(18, _userId) {
        // Leave the body of the function blank
    }
}
