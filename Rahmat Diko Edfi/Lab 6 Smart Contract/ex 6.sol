//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
struct Product
 {
    string name;
    uint id;
    // Add other properties of the Product struct here
}
contract factory {
    

Product[] public products;

function createProduct(string memory _name, uint _id) private {
    Product memory newProduct = Product(_name, _id);
    products.push(newProduct);
}

}