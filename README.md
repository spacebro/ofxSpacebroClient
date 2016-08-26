An addon for openFrameworks to connect to [spacebro](https://github.com/soixantecircuits/spacebro) with a single line.

# Install

You need this repo, and clone other addons. We've prepared a script to do that for you.
Install [openFrameworks](http://openframeworks.cc) and then
```
cd your_of_path/addons
git clone git@github.com:soixantecircuits/ofxSpacebroClient.git
cd ofxSpacebroClient
bash clone_addons.sh
```

# Usage

First, you need to regsiter your events
```c++
// Use spacebroClient.registerEvent(eventName) to create ofEvents you can listen to
ofAddListener(spacebroClient.registerEvent("stuff"), this, &ofApp::onStuff)
```

Then you can setup your client and register to the server
```c++
// Use spacebroClient.setup(clientName) to register as clientName to the server
spacebroClient.setup("ofxSpacebroClient")
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
