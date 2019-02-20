import React, { Component } from "react";
import logo from "./logo.svg";
import "./App.css";
import Map from "./components/MapComponent";
import Sidebar from "./components/SidebarComponent"

class App extends Component {
  render() {
    return (
      <React.Fragment>
        <Sidebar />
        <Map />
      </React.Fragment>
    );
  }
}

export default App;
