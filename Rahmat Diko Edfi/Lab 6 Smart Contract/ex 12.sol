//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
contract Marketplace {
    struct Product {
        uint id;
        string name;
        address owner;
    }

    Product[] public products;

    mapping(uint => address) public productToOwner;
    mapping(address => uint) public ownerProductCount;

    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function _generateRandomId(string memory _str) private pure returns (uint) {
        uint rand = uint(keccak256(abi.encode(_str)));
        return rand;
    }

    function _createProduct(string memory _name, uint ) private {
        uint randId = _generateRandomId(_name);
        uint productId = products.length;
        products.push(Product(productId, _name, msg.sender));
        productToOwner[productId] = msg.sender;
        ownerProductCount[msg.sender]++;
        emit NewProduct(productId, _name, randId);
    }

    function createProduct(string memory _name) public {
        _createProduct(_name, 10000);
    }

    function getProductsByOwner(address _owner) external view returns (uint[] memory) {
        uint counter = 0;
        uint[] memory result = new uint[](ownerProductCount[_owner]);
        for (uint i = 0; i < products.length; i++) {
            if (productToOwner[i] == _owner) {
                result[counter] = i;
                counter++;
            }
        }
        return result;
    }
}