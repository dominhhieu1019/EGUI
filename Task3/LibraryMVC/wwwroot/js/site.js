class LibraryData extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            library: [],
            titleFilter: '',
            authorFilter: '',
            yearFilter:'',
            yearList: []
            //filteredLibrary: []
        };

        axios.get('/api/Library/GetYearList')
        .then(response => 
            this.setState({ yearList: response.data })   
        )        

        this.handleChange = this.handleChange.bind(this);
        //this.handleFilter = this.handleFilter.bind(this);
        this.cancelFilter = this.cancelFilter.bind(this);
    }

    componentDidMount() {
        axios.get('/api/Library/Index')
            .then(response => 
                this.setState({ library: response.data })   
            )
    }

    delete(id) {
        console.log(id);
        axios.get('https://localhost:5001/api/Library/Delete/' + id)
            .then(result => 
                this.setState({library: this.state.library.filter(book => book.id !==id)})
            )
    }

    handleChange(event) {
        const name = event.target.name;
        const value = event.target.value;

        this.setState({
            [name]: value
        })
    }

    renderLibrary() {
        let filteredLibrary = this.state.library.filter(
            (book) => {
                return book.title.indexOf(this.state.titleFilter) !== -1;  
            }
        );
        filteredLibrary = filteredLibrary.filter(
            (book) => {
                return book.author.indexOf(this.state.authorFilter) !== -1;
            }
        )

        filteredLibrary = filteredLibrary.filter(
            (book) => {
                return book.year == this.state.yearFilter || this.state.yearFilter == '';
            }
        )


        return filteredLibrary.map(book =>(
            <tr key={book.id}>
                <td></td>
                <td>{book.title}</td>
                <td>{book.author}</td>
                <td>{book.year}</td>
                <td>
                    <button className="btn btn-default" onClick={() => this.props.edit(book.id)}>Edit</button> &nbsp; 
                    <button className="btn btn-default" onClick={() => this.delete(book.id)}>Delete</button>
                </td>    
            </tr>
        ))
    }

    filter(){
        // this.setState({filteredLibrary : this.state.library.filter(
        //     (book) => {
        //         return book.title.indexOf(this.state.titleFilter) !== -1;  
        //     }
        // )})
    }

    cancelFilter(){
        // document.getElementById("a").value = '';
        // document.getElementById("t").value = '';
        // document.getElementById("y").value = '';
    }

    renderFilter() {
        
        return (
            <div>
                <div className="form-row">
                    <div className="col">
                        <input id='t' type="text" class="form-control" placeholder="Title" name="titleFilter" onChange={this.handleChange}  defaultValue={this.state.titleFilter}/>
                    </div>
                    <div className="col">
                        <input id='a' type="text" class="form-control" placeholder="Author" name="authorFilter" onChange={this.handleChange} defaultValue={this.state.authorFilter} />
                    </div>
                    <div className="col">
                        <select id='y' class="form-control" data-val="true" name="yearFilter" onChange={this.handleChange} >
                            <option value="">Year</option>
                            {this.state.yearList.map(year =>
                                <option key={year} value={year}>{year}</option>
                                )}
                        </select>
                    </div>
                    <div className="form-group col">  
                        <button className="btn btn-default" onClick={() => this.filter()}>Filter</button>  
                        <button className="btn btn-default" onClisk={() => this.cancelFilter()}>Cancel</button>   
                    </div >
                </div>
            </div>
        )
    }

    render() {
        return (
            <div>
                <h1> Library Data</h1>
                {this.renderFilter()}
                <table className='table'>
                    <thead>
                        <tr>
                            <th></th>
                            <th>Title</th>
                            <th>Author</th>
                            <th>Year</th>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>
                        {this.renderLibrary()}
                    </tbody>
                </table>
                <button className="btn btn-default" onClick={() => this.props.add()}>Add Book</button>
            </div>
        );
    }
}

class AddEditBook extends React.Component {
    constructor(props) {
        super(props);
        this.initialState = {
            id: '',
            title: '',
            author: '',
            year: ''
        }
        

        if (props.book) {
            this.state = props.book;
            this.book = props.book;
        } else {
            this.state = this.initialState;
        }

        this.handleChange = this.handleChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleChange(event) {
        const name = event.target.name;
        const value = event.target.value;

        this.setState({
            [name]: value
        })
    }

    handleSubmit(event) {
        event.preventDefault();
        this.props.onFormSubmit(this.state);
        this.setState(this.initialState);
    }

    // handleCancel(event) {
    //     event.preventDefault();
    //     axios.get('/api/Library/Index')
    //         .then(response => 
    //             this.props.history.push('/')   
    //         )
    // }
    cancel = () => {
        axios.get('/api/Library/Index')
            .then(response => 
                this.setState({ library: library })   
            )
    }

    render() {
        let pageTitle = this.state.id ? <h2>Edit Book</h2> : <h2>Add Book</h2>;
        return (
            <div>
                {pageTitle}
                <form onSubmit={this.handleSubmit}>
                    <div className="form-group row" >  
                        <input type="hidden" name="id" value={this.state.id} />  
                    </div>
                    < div className="form-group row" >  
                        <label className=" control-label col-md-12" htmlFor="Title">Title</label>  
                        <div className="col-md-4">  
                            <input className="form-control" type="text" name="title" 
                            defaultValue={this.state.title} onChange={this.handleChange} />  
                        </div>  
                    </div >
                    < div className="form-group row" >  
                        <label className=" control-label col-md-12" htmlFor="Author">Author</label>  
                        <div className="col-md-4">  
                            <input className="form-control" type="text" name="author" 
                            defaultValue={this.state.author} onChange={this.handleChange}  />  
                        </div>  
                    </div >
                    < div className="form-group row" >  
                        <label className=" control-label col-md-12" htmlFor="Year">Year</label>  
                        <div className="col-md-4">  
                            <input className="form-control" type="text" name="year" 
                            defaultValue={this.state.year} onChange={this.handleChange} />  
                        </div>  
                    </div >
                    <div className="form-group">  
                        <button type="submit" className="btn btn-default">Save</button>  
                        <button className="btn btn-default" onClick={() => this.state.cancel()}>Cancel</button>  
                    </div >
                </form>
            </div>
        )
    }
}

class App extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            isAdd: false,
            //error: nulll,
            response: {},
            book: {},
            isEdit: false, 
            editId: ''
        }
        this.onFormSubmit = this.onFormSubmit.bind(this);
    }

    onCreate() {
        this.setState({isAdd: true});
    }

    // onCreateEdit(id) {
    //     this.setState({isEdit: true, editId: id});
    // }

    onFormSubmit(data) {
        let apiUrl;;

        if(this.state.isEdit) {
            apiUrl = '/api/Library/Edit/' + data.id +'/' + data.title + '/' + data.author + '/' + data.year;
        } else {
            if(data.title && data.author && data.year) {
                apiUrl = '/api/Library/Create/' + data.title + '/' + data.author + '/' + data.year;
            }else{
                apiUrl = 'api/Library/Index';
            }
        }
        
        axios.get(apiUrl)
            .then(res =>
                this.setState({
                    book: res.data,
                    isAdd: false,
                    isEdit: false  
                })
            )
    }

    edit = id => {
        axios.get('api/Library/Index/' + id)
            .then(res =>
                this.setState({
                    book: res.data,
                    isEdit: true,
                    isAdd: false
                })
            )
    }
    
    add = () => {
        this.setState({
            isAdd: true,
            isEdit:false
        })
    }

    


    render() {
        let libraryForm;
        if(this.state.isAdd || this.state.isEdit) {
            libraryForm = <AddEditBook onFormSubmit={this.onFormSubmit} book={this.state.book}/>
        }

        return (
            <div className="App">
                {!this.state.isEdit && !this.state.isAdd && <LibraryData edit={this.edit} add={this.add}/>}
                {/* {!this.state.isAdd && !this.state.isEdit && <button className="btn btn-default" onClick={() => this.add()}>Add Book</button>} */}
                
                {libraryForm}
            </div>
        )
    }
}

ReactDOM.render(
    <App/>,
    document.getElementById('container')
)