const reFile = require('./reFile');

const React = require('react');
const ReactDOM = require('react-dom');

const ReFileComp = reFile.comp;

// const Comp = React.createClass({
//   getInitialState() {
//     return {clicks: 0};
//   },
//
//   handleClick() {
//     this.setState({clicks: this.state.clicks + 1});
//   },
//
//   render() {
//     return <ReFileComp name="asd">
//       asdfasdfsadf
//     </ReFileComp>;
//   }
// });

ReactDOM.render(<ReFileComp />, document.querySelector('.container'));
