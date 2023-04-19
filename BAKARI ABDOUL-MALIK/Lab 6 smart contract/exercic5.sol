//SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.10;
struct Product {
    string name;
    uint Id;
    // Add other properties of the Product struct here
}


contract factory 
{
 Product[] public products;  
}
