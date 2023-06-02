//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;

 contract SmartProducts {
    
    uint constant idModulus = 16; // Maximum value of 16-digit uint
    
    struct Product {
        string name;
        uint id;
    }
    
    Product[] public products;
    
    function _createProduct(string memory _name, uint _id) private {
        products.push(Product(_name, _id));
    }
    
    function _generateRandomId(string memory _str)  
    private pure returns (uint) 
    {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
    
    function createRandomProduct(string memory _name) public {
        uint randld = _generateRandomId(_name);
        _createProduct(_name, randld);
    }
}