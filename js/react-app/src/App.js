import React, { Component } from "react";
import "./App.css";
import Map from "./components/MapComponent";
import Sidebar from "./components/SidebarComponent";

const apiurl = "http://eit19gps-api-heroku.herokuapp.com/request";

// Mock: 17dh0cf43jfgl8   Real: 17dh0cf43jfkmm
const deviceID = "17dh0cf43jfkmm";

class App extends Component {
  state = {
    data: [
      { time: 1550665908, lat: 63.415, lng: 10.3 },
      { time: 1550666908, lat: 63.31, lng: 10.5 },
      { time: 1550667908, lat: 63.123456, lng: 10.4 },
      { time: 1550668908, lat: 63.09876, lng: 10.12345 }
    ],
    currentTime: 1550668908,
    currentMarker: { lat: 63.09876, lng: 10.12345 }
  };

  constructor(props) {
    super(props);
    this.changeMarker = this.changeMarker.bind(this);
  }

  changeMarker(time) {
    this.setState({ currentTime: time });
  }

  componentDidMount() {
    request().then(json => {
      if (json === null) {
        return;
      }
      this.setState({ data: json, currentTime: json[json.length - 1].time });
      console.log(this.state);
    });
  }

  componentDidUpdate(prevProps, prevState) {
    if (prevState.currentTime !== this.state.currentTime) {
      console.log("App update, current time: " + typeof this.state.currentTime);
      for (let i = 0; i < this.state.data.length; i++) {
        console.log(typeof this.state.data[i].time);
        if (this.state.currentTime === this.state.data[i].time) {
          this.setState({
            currentMarker: {
              lat: this.state.data[i].lat,
              lng: this.state.data[i].lng
            }
          });
          console.log("updated marker in state");
          return;
        }
      }
      this.setState({
        currentMarker: {
          lat: this.state.data[this.state.data.length - 1].lat,
          lng: this.state.data[this.state.data.length - 1].lng
        }
      });
      console.log("marker to default");
    }

    return;
  }

  render() {
    return (
      <div className="rows">
        <Sidebar
          height={window.innerHeight + "px"}
          width={window.innerWidth * 0.2 + "px"}
          data={this.state.data}
          changeMarker={this.changeMarker}
          currentTime={this.state.currentTime}
        />
        <Map
          height={window.innerHeight + "px"}
          width={window.innerWidth * 0.8 + "px"}
          data={this.state.currentMarker}
        />
      </div>
    );
  }
}

const request = async () => {
  const response = await fetch(apiurl + "?id=" + deviceID);
  console.log(response.status);
  if (response.status === 404) {
    return null;
  }
  const json = await response.json();
  console.log(json);
  return json;
};

export default App;
