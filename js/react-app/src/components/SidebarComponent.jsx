import React, { Component } from "react";
import "./SidebarComponent.css";
import styled from "styled-components";

const Wrapper = styled.div`
  width: ${props => props.width};
  height: ${props => props.height};
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
            className="btn btn-primary"
            onClick={this.buttonClicked}
            value={tag.time}
            key={tag.time}
          >
            {tag.time}
          </button>
        ))}
      </Wrapper>
    );
  }
}
