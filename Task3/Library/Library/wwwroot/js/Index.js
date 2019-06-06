//import React from './src/react.development'
//import ReactDOM from './react-dom.development'
//import { BrowserRouter as Router, Route } from './src/react-router-dom'
//import registerServiceWorker from './registerServiceWorker'
//import Create from './components/Create'
//import Edit from './components/Edit'
//import App from './App';

class App extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            libraryList: []
        };
    }

    componentDidMount() {
        axios.get('http://localhost:54744/api/Data/Index')
            .then(res => {
                this.setState({ libraryList: res.data });
                console.log(this.state.libraryList)
            });
    }

    delete(id) {
        axios.get('http://localhost:54744/api/Data/Delete/' + id)
            .then((result) => {
                this.props.history.push("/")
            });
    }

    render() {
        return (
            <div>
                <h1> Library Data</h1>
                <p>
                    <Link to="/Create">Add new book</Link>
                </p>
                <table className='table'>
                    <thead>
                        <tr>
                            <th></th>
                            <th>Title</th>
                            <th>Author</th>
                            <th>Year</th>
                        </tr>
                    </thead>
                    <tbody>
                        {this.state.libraryList.map(book =>
                            <tr key={book.Id}>
                                <td></td>
                                <td>{book.Title}</td>
                                <td>{book.Author}</td>
                                <td>{book.Year}</td>
                                <td>
                                    <Link to={'/Edit/${this.state.book.ID}'}>Edit</Link>&nbsp
                                    <a onClick={this.delete.bind(this, this.state.book.ID)}>Delete</a>
                                </td>
                            </tr>
                        )}
                    </tbody>
                </table>
            </div>
        );
    }
}

ReactDOM.render(
    <Router>
        <div>
            <BrowserRouter exact path='/' component={App} />
            <BrowserRouter path='/edit/:id' component={Edit} />
            <BrowserRouter path='/create' component={Create} />
        </div>
    </Router>,
    document.querySelector('#root1')
);
registerServiceWorker();