// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract SimpleDigitalBank {


    mapping(address => uint256) private balances;

    function deposit(uint256 _amount) public {
        balances[msg.sender] += _amount;
    }

    function withdraw(uint256 _amount) public {
        require(balances[msg.sender] >= _amount, "Error: Insufficient balance.");
        
        balances[msg.sender] -= _amount;
    }


    function showBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}
