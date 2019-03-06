import React, { Component } from "react";
import "./SidebarComponent.css";
import styled from "styled-components";
import "bootstrap/dist/css/bootstrap.css";

const Wrapper = styled.div`
  width: ${props => props.width};
  height: ${props => props.height};
  overflow: scroll;
  overflow-x: hidden;
`;

export default class Sidebar extends Component {
  constructor(props) {
    super(props);
    this.buttonClicked = this.buttonClicked.bind(this);
  }

  buttonClicked(event) {
    this.props.changeMarker(parseInt(event.target.value, 10));
  }

  render() {
    return (
      <Wrapper
        width={this.props.width}
        height={this.props.height}
        style={{ backgroundColor: "#9DA1C9" }}
      >
        {this.props.data.map(tag => (
          <button
            type="button"
            className={
              this.props.currentTime === tag.time
                ? "btn btn-success"
                : "btn btn-primary"
            }
            onClick={this.buttonClicked}
            value={tag.time}
            key={tag.time}
          >
            {new Date(tag.time * 1000).toLocaleString()}
          </button>
        ))}
      </Wrapper>
    );
  }
}
