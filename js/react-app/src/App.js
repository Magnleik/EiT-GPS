import React, { Component } from "react";
import "./App.css";
import Map from "./components/MapComponent";
import Sidebar from "./components/SidebarComponent";

const apiurl = "http://eit19gps-api-heroku.herokuapp.com/request";
const deviceID = "17dh0cf43jfkmm";

class App extends Component {
  state = {
    data: [
      { time: 1550665908, lat: 63.415, lng: 10.3 },
      { time: 1550666908, lat: 63.31, lng: 10.5 },
      { time: 1550667908, lat: 63.123456, lng: 10.4 },
      { time: 1550668908, lat: 63.09876, lng: 10.12345 }
    ]
  };

  componentDidMount() {
    request().then(json => {
      this.setState({ data: json });
    });
  }

  render() {
    return (
      <div className="rows">
        <Sidebar
          height={window.innerHeight + "px"}
          width={window.innerWidth * 0.2 + "px"}
          data={this.state.data}
        />
        <Map
          height={window.innerHeight + "px"}
          width={window.innerWidth * 0.8 + "px"}
          data={this.state.data}
        />
      </div>
    );
  }
}

const request = async () => {
  const response = await fetch(apiurl + "?id=" + deviceID);
  const json = await response.json();
  console.log(json);
  return json;
};

export default App;
