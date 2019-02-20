import React from "react";
import L from "leaflet";
import "leaflet/dist/leaflet.css";
import styled from "styled-components";

const Wrapper = styled.div`
  width: ${props => props.width};
  height: ${props => props.height};
`;

const Positions = [
  [63, 10],
  [63.43, 10.395],
  [63.03, 10.405],
  [63.612, 10.124]
];

export default class Map extends React.Component {
  componentDidMount() {
    this.map = L.map("map", {
      center: [63, 10],
      zoom: 9,
      zoomControl: false
    });

    L.tileLayer(
      "http://opencache.statkart.no/gatekeeper/gk/gk.open_gmaps?layers=norges_grunnkart_graatone&zoom={z}&x={x}&y={y}",
      {
        detectRetina: true,
        maxZoom: 20,
        maxNativeZoom: 17
      }
    ).addTo(this.map);
    for (let i = 0; i < Positions.length; i++) {
        let position = Positions[i];
        let marker = L.marker(position).addTo(this.map);
        marker.bindPopup("<b>Position " + (i+1) + "</b><br>Lat:" + position[0] + "</br><br>Lng:" + position[1] + "</br>")
    }
  }

  render() {
    return <Wrapper width={this.props.width} height={this.props.height} id="map" />;
  }
}
