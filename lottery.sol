// SPDX-License-Identifier: MIT
pragma solidity >=0.8.0;

contract lottery{
    address public manager;
    address payable[] public  participants;

    constructor(){
        manager=msg.sender;
    }

    receive() external payable {
        require(msg.value==500);
        participants.push(payable(msg.sender));
    }

    function participantsCount() public view returns(uint)
    {
        return  participants.length;
    }

    function getBalance() public view returns(uint)
    {
        require(msg.sender==manager);
        return address(this).balance;
    }

    function generateRandomNumber() internal view  returns(uint)
    {
        return uint(keccak256(abi.encodePacked(blockhash(block.number-1),block.timestamp,participants.length)));
    }

    function selectWinner() public
    {
        require(msg.sender==manager);
        require(participants.length>=3);
        uint r=generateRandomNumber();
        uint winner=r%participants.length;
        address payable wa=participants[winner];
        wa.transfer(getBalance());
        participants=new address payable[](0);
    }

}