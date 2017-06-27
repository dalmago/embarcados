/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  StyleSheet,
  Text,
  View,
  Button,
  TouchableOpacity,
  TouchableHighlight,
  Toast,
} from 'react-native';

import BluetoothSerial from 'react-native-bluetooth-serial';

export class App extends Component {
  constructor(props) {
    super(props);
    this.state = { estado: 0, devs: BluetoothSerial.list() };
  }
  render() {
    var blankSpace = <Text style={{fontSize: 50}}>{'\n'}</Text>;
    
    return (
      <View style={{
          flex: 1,
          justifyContent: "center",
          alignItems: "center",
          backgroundColor: "rgba(147,179,215,1)",
        }}>
        {(this.state.estado == 0)?
        <View style={{
          flex: 1,
          justifyContent: "center",
          alignItems: "center"
        }}>
          <Text>Dispositivo pareado:</Text>
          <Text>None</Text>
          <Text></Text>
          <Text></Text>
          <Button
            onPress={gameInit}
            title="Iniciar Jogo"
            color="rgba(0,90,190,1)"
          />
        </View>        
        
        :
        
        <View style={{flex: 1}}>
          {blankSpace}
          <View style={{flex: 1, 
                        justifyContent: 'center',
                        alignItems: 'center'}}>
            <Text style={{fontWeight: 'bold'}}>Entre com a sequência de cores visualizada:</Text>
          </View>
        
          <View style={{
            flex: 10,
            flexDirection: 'row',
            justifyContent: 'center',
            alignItems: 'center'
          }}>          
            <TouchableHighlight
              onPress={() => {this.colorPressed('R')}}
              activeOpacity={75 / 100}
              underlayColor={"rgb(210,210,210)"}>
              <View style={[styles.rgb_block, {backgroundColor: "rgb(208,2,27)"}]} />
            </TouchableHighlight>

            <TouchableHighlight
              onPress={() => {this.colorPressed('G')}}
              activeOpacity={75 / 100}
              underlayColor={"rgb(210,210,210)"}>
              <View style={[styles.rgb_block, {backgroundColor: "rgb(126,211,33)"}]} />
            </TouchableHighlight>

            <TouchableHighlight
              onPress={() => {this.colorPressed('B')}}
              activeOpacity={75 / 100}
              underlayColor={"rgb(210,210,210)"}>
              <View style={[styles.rgb_block, {backgroundColor: "rgb(0,122,255)"}]} />
            </TouchableHighlight>          
          </View>
        </View>
        }       
      </View>
    );
  }
  
  colorPressed(color){
    BluetoothSerial.write(color).then((res) => {
      Toast.showShortBottom('Successfuly wrote to device');
      })
      .catch((err) => {Toast.showShortBottom(err.message);})   
    }
  
  gameInit(){
    BluetoothSerial.connect(device.id)
    .then((res) => {
      Toast.showShortBottom('Connected to device');
      this.setState({ estado: 1 });
    })
    .catch((err) => Toast.showShortBottom(err.message));
  }
}

const styles = StyleSheet.create({
  rgb_block: {
    width: 100, 
    height: 100,
     margin: 10, 
    borderColor: "black", 
    borderWidth: 1,
  }
});