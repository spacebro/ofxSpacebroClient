An addon for openFrameworks to connect to [spacebro](https://github.com/soixantecircuits/spacebro) with a single line.

# Install

You need this repo, and clone other addons. We've prepared a script to do that for you.
```
git clone git@github.com:soixantecircuits/ofxSpacebroClient.git
cd ofxSpacebroClient
bash clone_addons.sh
```

# Test

## Run spacebro

Spacebro receives and broadcasts all messages to its clients.

```
git clone git@github.com:soixantecircuits/spacebro.git
cd spacebro
npm i
npm start
```

## Run spacebro-client example

Run some other example to send data to ofxSpacebroClient example.

```
git clone git@github.com:soixantecircuits/spacebro-client.git
cd spacebro-client
npm i
npm start
```

## Run this example

Now you're ready to receive data

```
cd example
make
make run
```
