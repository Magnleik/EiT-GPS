import React, { Component } from "react";
import "./App.css";
import Map from "./components/MapComponent";
import Sidebar from "./components/SidebarComponent"

class App extends Component {

  readJson() {

  }

  render() {
    return (
      <div className="rows">
        <Sidebar height={window.innerHeight + "px"} width={window.innerWidth*0.2 + "px"}/>
        <Map height={window.innerHeight + "px"} width={window.innerWidth*0.8 + "px"}/>
      </div>
    );
  }
}

export default App;
