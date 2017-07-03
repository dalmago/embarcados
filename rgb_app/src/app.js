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
  ToastAndroid,
} from 'react-native';

import BluetoothSerial from 'react-native-bluetooth-serial';

export class App extends Component {
  constructor(props) {
    super(props);
    this.state = { estado: 0 };
                  
    // MAC: "48:D7:05:DA:D3:AE"
    // RGB: "20:17:02:20:42:79"      
   
    BluetoothSerial.connect("20:17:02:20:42:79").then((res) => {
      console.log('CONNECTED', res);
      ToastAndroid.show("Bluetooth connected!", ToastAndroid.SHORT);       
    }).catch((err) => {
      console.log('Error connecting', err);
      ToastAndroid.show("ERROR CONNECTING BLUETOOTH", ToastAndroid.LONG);
    });
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
          <Text style={{fontWeight: 'bold', fontSize:17}}>O dispositivo bluetooth{'\n'}deve estar conectado</Text>
          <Text></Text>
          <Text></Text>
          <Button
            onPress={() => this.gameInit()}
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
              onPress={() => this.colorPressed('r')}
              activeOpacity={75 / 100}
              underlayColor={"rgb(210,210,210)"}>
              <View style={[styles.rgb_block, {backgroundColor: "rgb(208,2,27)"}]} />
            </TouchableHighlight>

            <TouchableHighlight
              onPress={() => this.colorPressed('g')}
              activeOpacity={75 / 100}
              underlayColor={"rgb(210,210,210)"}>
              <View style={[styles.rgb_block, {backgroundColor: "rgb(126,211,33)"}]} />
            </TouchableHighlight>

            <TouchableHighlight
              onPress={() => this.colorPressed('b')}
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
    BluetoothSerial.write(color).then((res) => {}).catch((err) => {
      ToastAndroid.show("Error color: " + err.message, ToastAndroid.SHORT);
      console.error("Error color: " + err.message);
    });
  }
  
  gameInit(){    
    BluetoothSerial.write('i').then((res) => {
      ToastAndroid.show("Atenção na sequência de cores!", ToastAndroid.LONG);
      console.log("Atenção na sequência de cores!");      
      
      this.interval = setInterval(() => this.waitForOk(), 500);
    })
    .catch((err) => {
      ToastAndroid.show("Error i: " + err.message, ToastAndroid.SHORT);
      console.error("Error i: " + err.message);
    });  
  }
  
  waitForOk(){
    BluetoothSerial.available().then((length) => {
      BluetoothSerial.readFromDevice().then((data) => {
        if (data !== ""){
          console.log('data received: ' + data);
        
          if (data == 'o'){
            clearInterval(this.interval);
            this.setState({ estado: 1 });

            this.interval = setInterval(() => this.waitForScore(), 500);
          }
        }
      }).catch((err) => {
        ToastAndroid.show("Error o: " + err.message, ToastAndroid.SHORT);
        console.error("Error o: " + err.message);
      });
    }); 
  }
  
  waitForScore(){
    BluetoothSerial.available().then((length) => {
      BluetoothSerial.readFromDevice().then((data) => {    
        if (data !== ""){
          // data = parseInt(data);
          
          data = data.charCodeAt(0);
          
          ToastAndroid.show("Seu score: " + data, ToastAndroid.LONG);
          console.log("Seu score: " + data);

          clearInterval(this.interval);
          this.setState({ estado: 0 });
        }
      }).catch((err) => {
        ToastAndroid.show("Error score: " + err.message, ToastAndroid.SHORT);
        console.error("Error score: " + err.message);
      });
    }); 
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