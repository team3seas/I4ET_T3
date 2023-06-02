//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
struct Product {
string name;
 uint id;
}

contract ProductManager {

  uint constant idModulus = 16;
    uint productCount;

    mapping (uint => address) public productToOwner;
    mapping (address => uint) public ownerProductCount;

    event NewProduct(uint indexed ArrayProductID, string name, uint id);

    function _generateRandomId(string memory _str) private pure returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }

  Product[] public products;


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

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }
//exerce11
    function getProductsByOwner(address _owner) external view returns (uint[] memory) {
        uint[] memory result = new uint[](ownerProductCount[_owner]);
        uint counter = 0;
        for (uint i = 0; i < products.length; i++) {
            if (productToOwner[i] == _owner) {
                result[counter] = i;
                counter++;
            }
        }
        return result;
    }
}