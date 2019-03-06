import React, { Component } from 'react';
import L from "leaflet";
import "leaflet/dist/leaflet.css";
import styled from "styled-components";

const Wrapper = styled.div`
  width: ${props => props.width};
  height: ${props => props.height};
`;

let marker;

export default class Map extends Component {
  
  componentDidMount() {
    this.map = L.map("map", {
      center: [63, 10],
      zoom: 9,
      zoomControl: false
    });
    
    L.tileLayer(
      "http://opencache.statkart.no/gatekeeper/gk/gk.open_gmaps?layers=norges_grunnkart_graatone&zoom={z}&x={x}&y={y}",
      {
        attribution: '<a href="http://www.kartverket.no/">Kartverket</a>',
        detectRetina: true,
        maxZoom: 20,
        maxNativeZoom: 17
      }
    ).addTo(this.map);
    console.log(this.props.data);
    let position = this.props.data;
    marker = L.marker(position);
    marker.addTo(this.map);
    marker.bindPopup("</b><br>Lat:" + position.lat + "</br><br>Lng:" + position.lng + "</br>");
  }
  
  componentDidUpdate() {
    let position = this.props.data;
    let newLatLng = new L.LatLng(position.lat, position.lng);
    marker.setLatLng(newLatLng);
    marker.bindPopup("</b><br>Lat:" + position.lat + "</br><br>Lng:" + position.lng + "</br>");
  }

  render() {
    return <Wrapper width={this.props.width} height={this.props.height} id="map" />;
  }
}
