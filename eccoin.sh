#!/bin/bash

docker exec -it eccoin_node$1_1 ./ECCoin/src/ECCoind -testnet0 -printtoconsole -rpcport=30001 -rpcuser=yourusername -rpcpassword=yourpassword -rpcallowip=0.0.0.0/0 ${@:2}

