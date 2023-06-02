//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
struct Product {
string name;
 uint id;
}
contract constants 
{
 uint constant idModulus = 16;
    
    Product[] public products;

    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function _generateRandomId(string memory _str) private pure returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }


    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product(_name, _id);
        products.push(newProduct);
        uint productId = products.length - 1;
        emit NewProduct(productId, _name, _id);
    }

    function createRandomProduct(string memory _name) public {
        uint randld = _generateRandomId(_name);
        _createProduct(_name, randld);
    }
}
