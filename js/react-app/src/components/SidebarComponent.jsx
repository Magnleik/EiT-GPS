import React, { Component } from "react";
import styled from "styled-components";

const Wrapper = styled.div`
  width: ${props => props.width};
  height: ${props => props.height};
`;

export default class Sidebar extends Component {
  render() {
    return <Wrapper width={this.props.width} height={this.props.height} style={{backgroundColor: "#000000"}}/>;
  }
}
