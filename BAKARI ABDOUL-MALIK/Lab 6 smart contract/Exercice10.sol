//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
struct Product {
string name;
 uint id;
}

contract ProductManager {

    Product[] public products;

    mapping (uint => address) public productToOwner;
    mapping (address => uint) public ownerProductCount;

    event NewProduct(uint indexed ArrayProductId, string name, uint id);
    

  function _createProduct(string memory _name, uint _id) private {
    Product memory newProduct = Product({
        name: _name,
        id: _id
    });
    products.push(newProduct);
    uint productId = products.length - 1;
    productToOwner[productId] = msg.sender;
    ownerProductCount[msg.sender]++;
    emit NewProduct(productId, _name, _id);
}

uint constant idModulus = 16;
    function _generateRandomId(string memory _str) private pure returns (uint) {
        bytes32 hash = keccak256(abi.encodePacked(_str));
        uint rand = uint(hash);
        return rand % idModulus;
    }

    function createRandomProduct(string memory _name) public {
        uint randld = _generateRandomId(_name);
        _createProduct(_name, randld);
    }
}
