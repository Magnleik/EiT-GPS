import React, { Component } from "react";
import "./App.css";
import Map from "./components/MapComponent";
import Sidebar from "./components/SidebarComponent"


const apiurl = "http://eit19gps-api-heroku.herokuapp.com/request";
const deviceID = "id1"

class App extends Component {

  state = {"data": [
    {"time": 1550665908, "lat": 63.415, "lng": 10.3},
    {"time": 1550666908, "lat": 63.310, "lng": 10.5},
    {"time": 1550667908, "lat": 63.123456, "lng": 10.4},
    {"time": 1550668908, "lat": 63.09876, "lng": 10.12345}
  ]};

  componentDidMount() {
    fetch(apiurl + "?id=" + deviceID, {mode: 'cors', headers: {Accept: 'application/json', 'Access-Control-Allow-Origin': '*'}})
      .then(res => {
        console.log(res)
        res.json(); 
      })
      .then(data => {
        this.setState({data: data});
        // console.log(data);
      })
  }

  render() {
    return (
      <div className="rows">
        <Sidebar height={window.innerHeight + "px"} width={window.innerWidth*0.2 + "px"} data={this.state.data}/>
        <Map height={window.innerHeight + "px"} width={window.innerWidth*0.8 + "px"} data={this.state.data}/>
      </div>
    );
  }
}

export default App;
